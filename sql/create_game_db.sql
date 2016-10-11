-- リセット
DROP TABLE t_player_data;
DROP TABLE t_enemy_data;
DROP TABLE t_ranking;
DROP TABLE t_stage_data;
DROP TABLE m_map;
DROP TABLE m_lv_exp; 
DROP TABLE m_enemy;
DROP TABLE t_player;

-- キャラメイン
CREATE TABLE t_player(id int PRIMARY KEY, name text, score int, first_login date, last_login date);
INSERT INTO t_player (id, name) VALUES (1, '山賊');
INSERT INTO t_player (id, name) VALUES (2, '海賊');

-- 敵マスタ
CREATE TABLE m_enemy (id int PRIMARY KEY, name text);
INSERT INTO m_enemy (id, name) VALUES (1, '山賊');
INSERT INTO m_enemy (id, name) VALUES (2, '海賊');
INSERT INTO m_enemy (id, name) VALUES (3, '盗賊');
INSERT INTO m_enemy (id, name) VALUES (4, '戦士');
INSERT INTO m_enemy (id, name) VALUES (5, '騎士');
INSERT INTO m_enemy (id, name) VALUES (6, '剣士');

-- キャラステータス
CREATE TABLE t_player_data(player_id int REFERENCES t_player(id),
  name text, lv int, exp int, hp int, max_hp int, mp int, max_mp int, atk int, def int, spd int, luk int, mov int, cond int);
CREATE TABLE t_enemy_data ( enemy_id int PRIMARY KEY,
  name text, lv int, exp int, hp int, max_hp int, mp int, max_mp int, atk int, def int, spd int, luk int, mov int, cond int);

-- ランキングデータ
CREATE TABLE t_ranking(player_id int REFERENCES t_player(id), high_score int);

-- ステージデータ, マップデータ
CREATE TABLE t_stage_data(stage_id int PRIMARY KEY, avg_lv int);
CREATE TABLE m_map(id int, val text);
  INSERT INTO m_map (id, val) VALUES (1, '1,0,1,0,1\r\n1,1,0,1,1\r\n1,0,0,0,1\r\n1,1,0,1,1\r\n1,0,1,0,1');

-- レベル対経験値マスタ生成(暫定)
-- BEGIN --
  CREATE TABLE m_lv_exp(lv int PRIMARY KEY, next_exp int);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (1, 10);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (2, 20);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (3, 30);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (4, 40);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (5, 50);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (6, 60);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (7, 70);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (8, 80);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (9, 90);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (10, 100);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (11, 110);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (12, 120);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (13, 130);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (14, 140);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (15, 150);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (16, 160);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (17, 170);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (18, 180);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (19, 190);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (20, 200);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (21, 210);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (22, 220);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (23, 230);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (24, 240);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (25, 250);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (26, 260);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (27, 270);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (28, 280);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (29, 290);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (30, 300);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (31, 310);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (32, 320);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (33, 330);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (34, 340);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (35, 350);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (36, 360);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (37, 370);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (38, 380);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (39, 390);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (40, 400);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (41, 410);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (42, 420);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (43, 430);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (44, 440);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (45, 450);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (46, 460);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (47, 470);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (48, 480);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (49, 490);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (50, 500);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (51, 510);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (52, 520);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (53, 530);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (54, 540);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (55, 550);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (56, 560);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (57, 570);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (58, 580);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (59, 590);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (60, 600);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (61, 610);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (62, 620);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (63, 630);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (64, 640);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (65, 650);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (66, 660);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (67, 670);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (68, 680);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (69, 690);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (70, 700);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (71, 710);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (72, 720);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (73, 730);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (74, 740);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (75, 750);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (76, 760);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (77, 770);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (78, 780);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (79, 790);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (80, 800);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (81, 810);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (82, 820);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (83, 830);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (84, 840);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (85, 850);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (86, 860);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (87, 870);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (88, 880);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (89, 890);

  INSERT INTO m_lv_exp (lv, next_exp) VALUES (90, 900);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (91, 910);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (92, 920);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (93, 930);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (94, 940);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (95, 950);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (96, 960);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (97, 970);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (98, 980);
  INSERT INTO m_lv_exp (lv, next_exp) VALUES (99, 990);
-- END --
