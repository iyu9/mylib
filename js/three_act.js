
			var container, stats;
			var camera, scene, renderer;
			var particleMaterial;

			var raycaster;
			var mouse;
			var time = 0;
			var clock = 0;

			var player;

			//プレイヤー操作モード
			const NONE = 0;
			const FLYING = 1;

			//方向
			const RIGHT    = 0;
			const LEFT     = 1;
			const FORWARD  = 2;
			const BACKWARD = 3;

			//衝突判定用
			var bullets　= [];

			var chip = [];
			var enemies = [];

			var dae;

			const CM_TP = 0;
			const CM_FP = 1;

			const GRAVITY = 9.8;

			init();
			animate();

			function init() {

				container = document.createElement( 'div' );
				document.body.appendChild( container );

				var info = document.createElement( 'div' );
				info.style.position = 'absolute';
				info.style.top = '10px';
				info.style.width = '100%';
				info.style.textAlign = 'center';
				info.innerHTML = '<a href="http://threejs.org" target="_blank">three.js</a> - ACT-STG prot </br></br> Z: Jump X:Shot Arrow key: Move ';
				container.appendChild( info );

				camera = new THREE.PerspectiveCamera( 70, window.innerWidth / window.innerHeight, 1, 10000 );
				camera.position.set( 0, 0, 300 );
				camera.mode = 0;

				scene = new THREE.Scene();

				var geometry = new THREE.BoxGeometry( 100, 100, 100 );

				//--ADDED
				renderer = new THREE.CanvasRenderer();

				//shadertest
				/*
				var gl = renderer.context;
				var glVertexShader = new THREE.WebGLShader(gl, gl.VERTEX_SHADER, "x_vertex.shader");
				var glFlagmentShader = new THREE.WebGLShader(gl, gl.FLAGMENT_SHADER, "x_flagment.shader");

				var program = gl.createProgram();
				gl.attachShader(program, glVertexShader);
				gl.attachShader(program, glFragmentShader);
				gl.linkProgram(program);
				*/

				clock = new THREE.Clock(true);

				//モデルデータ読み込み
				/*
				var loader = new THREE.ColladaLoader();
				loader.load( 'sample.dae' , function ( collada ) {

					dae = collada.scene;
					dae.scale.x = dae.scale.y = dae.scale.z = 100;
					scene.add( dae );
				});
				*/

				//地面オブジェクト生成
				var helper = new THREE.GridHelper( 1000, 100 );
				helper.color1.setHex( 0x444444 );
				helper.color2.setHex( 0x444444 );
				helper.position.y = -100;
				scene.add( helper );

				var PI2 = Math.PI * 2;
				particleMaterial = new THREE.SpriteCanvasMaterial( {

					color: 0x000000,
					program: function ( context ) {

						context.beginPath();
						context.arc( 0, 0, 0.5, 0, PI2, true );
						context.fill();

					}

				} );

				//操作キャラ生成
				player = new THREE.Mesh( geometry, new THREE.MeshBasicMaterial( { color: 0x0000ff} ) );

				//敵生成
				var enemy = new THREE.Mesh( geometry, new THREE.MeshBasicMaterial( { color: 0x0000ff} ) );
				enemy.position.x = 200;
				enemy.position.y = 0;
				enemy.position.z = 200;

				enemy.scale.x = 1;
				enemy.scale.y = 1;
				enemy.scale.z = 1;

				enemy.update = function () {};

				enemies.push(enemy);

				//クラスパラメータ付加テスト
				var velocity = new Object();
				velocity.x = 0;
				velocity.y = 0;
				velocity.z = 0;
				player.velocity = velocity;
				player.falltime = 0;
				player.hp = 0;
				player.dir = 0;
				player.jumpstat = 0;
				player.mode = 0;
				player.score = 0;

				player.position.x = 0;
				player.position.y = 0;
				player.position.z = 0;

				player.scale.x = 0.25;
				player.scale.y = 1;
				player.scale.z = 0.25;

				//functions
				player.update = function () {};

				scene.add(player);

				const mapchip_dist = 100;

				//背景マップチップ生成
				var texture = THREE.ImageUtils.loadTexture('crate.gif');
				texture.anisotropy = renderer.getMaxAnisotropy();
				var material = new THREE.MeshBasicMaterial( { map: texture } );

				var map = [
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
					[1, 0, 1, 0, 1, 0, 1],
					[1, 1, 1, 1, 1, 1, 1],
				];

				console.log(map.length + ", " + map[0].length);

				for (var i = 0; i < map.length; i++) {
					for (var j = 0; j < map[i].length; j++) {

						//ブロック指定あり
						if (map[i][j] > 0) {
							var temp = new THREE.Mesh( geometry, material );
							temp.position.x = -600 + i * 100;
							temp.position.y = j * 100;
							temp.position.z = /*-300 + (Math.random() * 600); */-300;
							temp.scale.x = 1;
							temp.scale.y = 1;
							temp.scale.z = 1;
							scene.add(temp);

							chip.push(temp);
						}

					}
				}

				//ブロック生成
				block = new THREE.Mesh( geometry, material );
				block.position.x = -200;
				block.position.y = 0;
				block.position.z = 0;

				block.scale.x = 1;
				block.scale.y = 1;
				block.scale.z = 1;

				scene.add(block);

				raycaster = new THREE.Raycaster();
				mouse = new THREE.Vector2();

				//SWITCH
				//renderer = new THREE.CanvasRenderer();
				//renderer.setClearColor( 0xffffff );
				renderer.setClearColor( 0xf0f0f0 );
				renderer.setPixelRatio( window.devicePixelRatio );
				renderer.setSize( window.innerWidth, window.innerHeight );
				container.appendChild( renderer.domElement );

				stats = new Stats();
				stats.domElement.style.position = 'absolute';
				stats.domElement.style.top = '0px';
				container.appendChild( stats.domElement );

				//REGIST EVENT
				document.addEventListener( 'mousedown', onDocumentMouseDown, false );
				document.addEventListener( 'touchstart', onDocumentTouchStart, false );

				document.addEventListener( 'keydown', onDocumentKeyDown, false);

				//

				window.addEventListener( 'resize', onWindowResize, false );
				window.addEventListener( 'mousemove', onMouseMove, false );
			}

			function onWindowResize() {

				camera.aspect = window.innerWidth / window.innerHeight;
				camera.updateProjectionMatrix();

				renderer.setSize( window.innerWidth, window.innerHeight );

			}

			function onDocumentTouchStart( event ) {

				event.preventDefault();

				event.clientX = event.touches[0].clientX;
				event.clientY = event.touches[0].clientY;
				onDocumentMouseDown( event );

			}

			function onDocumentMouseDown( event ) {

				//Select Menu
				//window.location.href = 'index.html';

				//mode = (mode == 1) ? 0 : 1;


				event.preventDefault();

				shot();

				/*

				mouse.x = ( event.clientX / renderer.domElement.clientWidth ) * 2 - 1;
				mouse.y = - ( event.clientY / renderer.domElement.clientHeight ) * 2 + 1;

				raycaster.setFromCamera( mouse, camera );

				var intersects = raycaster.intersectObjects( objects );

				if ( intersects.length > 0 ) {

					intersects[ 0 ].object.material.color.setHex( Math.random() * 0xffffff );

					var particle = new THREE.Sprite( particleMaterial );
					particle.position.copy( intersects[ 0 ].point );
					particle.scale.x = particle.scale.y = 16;
					scene.add( particle );

				}

				*/

				/*
				// Parse all the faces
				for ( var i in intersects ) {

					intersects[ i ].face.material[ 0 ].color.setHex( Math.random() * 0xffffff | 0x80000000 );

				}
				*/
			}


			function onDocumentKeyDown (event) {
				event.preventDefault();

				console.log("keycode: " + event.keyCode);
				console.log("position: (" + camera.position.x + ", " + camera.position.y + ", " + camera.position.z + ")");

				var key = event.keyCode;

				//Z：ジャンプ
				if (key == 90) {

					//接地判定
					if (player.jumpstat == 0) {
						player.jumpstat = 1;
						player.position.y = 1;	//prottype test for jump
						player.velocity.y = 98;
					}

					//２段
					else if (player.jumpstat == 1) {
						player.jumpstat = 2;
						player.velocity.y += 98;
						player.falltime = 0;
					}
				}

				//X：ショット
				if (key == 88) {
					shot();
				}

				//C:キャンセル
				if (key == 67) {
					window.alert(player.position.y);
				}

				//矢印キー：方向移動
				//FORWARD
				if (key == 38) {
					//速度に移行予定
					player.position.z -= 1000 * clock.getDelta();
					player.velocity.z = -10;
					player.dir = FORWARD;
				}

				//BACKWARD
				if (key == 40) {
					player.position.z += 1000 * clock.getDelta();
					player.velocity.z = 10;
					player.dir = BACKWARD;
				}

				//RIGHT
				if (key == 39) {
					player.position.x += 1000 * clock.getDelta();
					player.velocity.x = 10;
					player.dir = RIGHT;
				}

				//LEFT
				if (key == 37) {
					player.position.x -= 1000 * clock.getDelta();
					player.velocity.x = -10;
					player.dir = LEFT;
				}

				//カメラ移動
				//W
				if (key == 87) {
					camera.position.z -= 10;
				}

				//S
				if (key == 83) {
					camera.position.z += 10;
				}

				//A
				if (key == 65) {
					camera.position.x -= 10;
				}

				//D
				if (key == 68) {
					camera.position.x += 10;
				}

				//カメラ視点切り替え
				//Q
				if (key == 81) {

					if (camera.mode == CM_TP){
						camera.mode = CM_FP;
						camera.position.x = player.position.x;
						camera.position.y = player.position.y;
						camera.position.z = player.position.z;
					} else  {
						camera.mode = CM_TP;
					}
				}

				//飛行モード
				//F
				if (key == 70) {
					player.mode = FLYING;
				}

			}

			//ショット生成
			function shot () {
				var geometry = new THREE.CubeGeometry( 100, 100, 100 );
				var bullet = new THREE.Mesh( geometry, new THREE.MeshBasicMaterial( { color: 0x000000} ) );

				bullet.position.x = player.position.x;
				bullet.position.y = player.position.y;
				bullet.position.z = player.position.z;

				bullet.scale.x = 0.1;
				bullet.scale.y = 0.1;
				bullet.scale.z = 0.1;

				//ショット情報格納
				bullet.dir = player.dir;

				bullets.push(bullet);

				scene.add(bullet);
			}

			//敵AI
			function UpdateAIProc( enemy ) {
				//とりあえず撃つだけ
				var geometry = new THREE.CubeGeometry( 100, 100, 100 );
				var bullet = new THREE.Mesh( geometry, new THREE.MeshBasicMaterial( { color: 0x000000} ) );

				bullet.position.x = player.position.x;
				bullet.position.y = player.position.y;
				bullet.position.z = player.position.z;

				bullet.scale.x = 0.1;
				bullet.scale.y = 0.1;
				bullet.scale.z = 0.1;

				//ショット情報格納
				bullet.dir = player.dir;
			}

			//マウス位置監視
			function onMouseMove( event ) {
				mouse.x = ( event.clientX / window.innerWidth ) * 2 - 1;
				mouse.y = ( event.clientY / window.innerHeight ) * 2 + 1;

				if (camera.mode == CM_FP) {
					console.log(mouse.x);
				}
			}

			function resetJumpingState(){
				player.rotation.x = 0;
				player.rotation.y = 0;
				player.rotation.z = 0;

				player.jumpstat = 0;
				player.velocity.y = 0;
			}

			//接触判定
			function isCollision (a, b) {
					if (
							 Math.abs(a.position.x - b.position.x) < 100 &&
							 Math.abs(a.position.y - b.position.y) < 100 &&
							 Math.abs(a.position.z - b.position.z) < 100
						 )
					{
						return true;
					}
					else {
						return false;
					}
			}

			//足場としての接触判定
			function isRideOn(player, platform) {

				//プレイヤーが上から落ちてきている
				if(player.y >= platform.y){
						if(isCollision(player, platform)) {
							return true;	
						}			
				}

				return false;
			}

			//フレーム更新
			function animate() {

				requestAnimationFrame( animate );

				//Update Time
				time += clock.getDelta();

				//Update Gravity Moving Position
				var isColFlag = false;

				//ブロックと接触
				/*
				//1.
				for(var i = 0; i < chip.length; i++) {
					if ( isCollision( player, chip[i] )) {
						isColFlag = true;
					}
				}
				//2.
				if ( isCollision( player, block ) || isRideOn(player,block)) {
					  isColFlag = true;
				}

				if ( isColFlag ) {
					resetJumpingState();
				}
				//判定フロー見直し
				else*/ if (player.position.y > 0) {

					player.position.y += (player.velocity.y * player.falltime) - (30 * GRAVITY * player.falltime * player.falltime);
					player.falltime += 1000 * clock.getDelta();

					//前回転
					switch(player.dir){
						case RIGHT:
							player.rotation.z -= 0.25;
							break;
						case LEFT:
							player.rotation.z += 0.25;
							break;
						case FORWARD:
							player.rotation.x += 0.25;
							break;
						case BACKWARD:
							player.rotation.x += 0.25;
							break;
					}
				}
				else {
					player.falltime = 0;
					player.jumpstat = 0;
					player.position.y = 0;

					//ジャンプ着地後、回転角リセット
					player.rotation.x = 0;
					player.rotation.y = 0;
					player.rotation.z = 0;
					player.velocity.y = 0;
				}

				//Update Velocity and Absorber
				if (Math.abs(player.velocity.x) > 1) {
					player.position.x += player.velocity.x;
					player.velocity.x *= 0.95;
				}

				if (Math.abs(player.velocity.z) > 1) {
					player.position.z += player.velocity.z;
					player.velocity.z *= 0.95;
				}

				//Update Flying Mode
				if (player.mode == FLYING) {

					player.position.y = 100;

					//Fly me To Direction
					if (player.dir == RIGHT) {
						player.position.x += 20;
					}

					if (player.dir == LEFT) {
						player.position.x -= 20;
					}

					if (player.dir == FORWARD) {
						player.position.z -= 20;
					}

					if (player.dir == BACKWARD) {
						player.position.z += 20;
					}

				}

				//Update CameraMode
				if (camera.mode == CM_FP) {
					camera.position.x = player.position.x;
					camera.position.y = player.position.y;
					camera.position.z = player.position.z;
				}

				//Update Shot
				for ( var i = 0; i < bullets.length; i++ ) {

					if ( bullets[i].dir == RIGHT ) {
						bullets[i].position.x += 20;
					}
					if ( bullets[i].dir == LEFT ) {
						bullets[i].position.x -= 20;
					}
					if ( bullets[i].dir == FORWARD ) {
						bullets[i].position.z -= 20;
					}
					if ( bullets[i].dir == BACKWARD ) {
						bullets[i].position.z += 20;
					}

					//ショット命中判定
					if ( isCollision( block, bullets[i] ) ) {
						scene.remove( block ) ;
						player.score += 100 ;
					}

					for ( var j = 0; j < chip.length; j++ ) {
						if ( isCollision( bullets[i], chip[j] ) ) {
							scene.remove( chip[j] );
							player.score += 100;
						}
					}
				}

				render();
				stats.update();

			}

			function render() {
				renderer.render( scene, camera );
				//camera.lookAt( player.position );
			}

