var lineChartData = {
  //x軸の情報
  labels : ['1月', '2月', '3月', '4月', '5月', '6月', '7月', '8月', '9月', '10月', '11月', '12月'],
  //各グラフの情報。複数渡すことができる。
  datasets : [
    {
      //rgba(220, 220, 220, 1)は、rgbと透過度。

      //線の色。ポイントの色を省略すると線の色と同じになる。
      strokeColor : "rgba(220, 220, 220, 1)",      
      //線の下側の色
      fillColor : "rgba(220, 220, 220, 0.5)",
      //ポイントの色
      pointColor : "rgba(220, 220, 220, 1)",
      //ポイントの枠の色
      pointStrokeColor : "rgba(220, 220, 220, 1)",
      //実際のデータ
      data : [1, 59, 90, 81, 56, 55, 40, 30, 10, 40, 48, 58],
      //凡例名
      'label'=>'data1'
    },
    {
      fillColor : "rgba(151, 187, 205, 0.5)",
      strokeColor : "rgba(151, 187, 205, 1)",
      pointColor : "rgba(151, 187, 205, 1)",
      pointStrokeColor : "#fff",
      data : [28, 48, 40, 19, 96, 27, 100, 33, 63, 31, 64, 51],
      'label'=>'data2'
    }
  ]
}

var option = {
  //縦軸の目盛りの上書き許可。これ設定しないとscale関連の設定が有効にならないので注意。
  scaleOverride : true,

  //以下設定で、縦軸のレンジは、最小値0から5区切りで35(0+5*7)までになる。
  //縦軸の区切りの数
  scaleSteps : 7,
  //縦軸の目盛り区切りの間隔
  scaleStepWidth : 5,
  //縦軸の目盛りの最小値
  scaleStartValue : 0,

  //アニメーション設定
  animation : false,

  //Y軸の表記（単位など）
  scaleLabel : "<%=value%>A",

  //ツールチップ表示設定
  showTooltips: false,

  //ドットの表示設定
  pointDot : false,

  //線を曲線にするかどうか。falseで折れ線になる。
  bezierCurve : false

  //凡例
  legendTemplate : "<% for (var i=0; i<datasets.length; i++){%><span style=\"background-color:<%=datasets[i].strokeColor%>\">&nbsp;&nbsp;&nbsp;</span>&nbsp;<%if(datasets[i].label){%><%=datasets[i].label%><%}%><br><%}%>"
}

//jQueryオブジェクト[0]とすれば、getContext("2D")できる。
var ctx = $('#lineChartCanvas')[0].getContext("2d");
//グラフ描画
var char = new Chart(ctx).Line(lineChartData,option);
//凡例のhtmlを取得して設定
$('#chart_legend').html(chart.generateLegend());
