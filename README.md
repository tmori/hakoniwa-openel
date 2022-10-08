# hakoniwa-openel

## 概要

箱庭上で TurtleBot3 を制御する Open-EL サンプルプロジェクトです．

## 設計

OpenELの設計としては，２種類の設計案があり，両方対応しています．

## ROS2実装

![image](https://user-images.githubusercontent.com/164193/194730237-aba61334-724c-411a-9f31-456c177d00ed.png)

## C++版箱庭実装

![image](https://user-images.githubusercontent.com/164193/194730245-96aec542-68f1-4d02-803b-138aa88645a2.png)


## ソースコード

箱庭上で動作する Open-EL サンプルアプリはこちらの main 関数です．

https://github.com/tmori/hakoniwa-openel/blob/main/src/main.cpp

また，箱庭上で動作可能な Open-ELデバイスソースは，設計毎に以下に配置しています．

* ROS2 実装
  * https://github.com/tmori/hakoniwa-openel/tree/main/ros_ws/src/openel_node/src/openel
* C++版箱庭実装
  * https://github.com/tmori/hakoniwa-openel/tree/main/hako_ws/src


## インストール手順

本リポジトリをクローンします．

```
git clone --recursive https://github.com/tmori/hakoniwa-openel.git
```

docker image を作成します．

```
sudo service docker start
cd hakoniwa-openel
bash docker/create-image.bash
```

docker 起動します．
```
bash docker/run.bash
```

docker コンテナ上で，hakoniwa-ros2sim ディレクトリへ移動します．
```
cd /root/workspace/openel/hakoniwa-ros2sim/ros2/workspace
```

hakoniwa-ros2sim のセットアップを以下の手順で実施します．

https://github.com/toppers/hakoniwa-ros2sim/blob/main/README_jp.md#%E8%B5%B7%E5%8B%95%E3%81%97%E3%81%9F-docker%E3%82%B3%E3%83%B3%E3%83%86%E3%83%8A%E4%B8%8A%E3%81%A7%E7%AE%B1%E5%BA%AD%E3%81%AEros%E7%92%B0%E5%A2%83%E3%82%92%E3%82%A4%E3%83%B3%E3%82%B9%E3%83%88%E3%83%BC%E3%83%AB

## ROS2実装向けの手順
### Open-EL側のビルド手順

docker コンテナの端末を以下の手順でもう１個起動します．

```
bash docker/attach.bash
```

docker コンテナ上で，Open-EL 側のビルドを行います．

```
cd /root/workspace/openel/ros_ws/src
bash build.bash
```

### シミュレーション手順

シミュレーション手順は，基本的に，hakoniwa-ros2sim と同じです．

https://github.com/toppers/hakoniwa-ros2sim/blob/main/README_jp.md#%E3%82%B7%E3%83%9F%E3%83%A5%E3%83%AC%E3%83%BC%E3%82%BF%E3%81%AE%E5%AE%9F%E8%A1%8C%E6%89%8B%E9%A0%86

ただし，TB3の制御プログラムの実行は，Open-ELのサンプルを使います．
そのため，Open-ELをビルドした docker コンテナ/ディレクトリ直下で以下のコマンドを実行してください．

```
bash run.bash openel_node TB3RoboModel
```

### デモンストレーション

上記の一連の操作（インストール以外）の操作デモ内容です．


https://user-images.githubusercontent.com/164193/193765479-5c8db856-9829-4ba8-bf8c-7b9381b8c88f.mp4

## C++版箱庭実装向けの手順
C++版箱庭の場合は，箱庭用のモジュールをいくつか利用する必要があるため，若干，ROS2実装よりも手順が多いです．

### Open-EL側のビルド手順

docker コンテナの端末を以下の手順で４個起動します．

#### 端末A：箱庭マスタ起動用
```
bash docker/attach.bash
```

#### 端末B：箱庭コマンド実行用
```
bash docker/attach.bash
```

#### 端末C：箱庭プロキシ起動用
```
bash docker/attach.bash
cd /root/workspace/openel/hakoniwa-ros2pdu/workspace/
bash build.bash
```

#### 端末D：OpenELビルド＆実行用
```
bash docker/attach.bash
cd /root//workspace/openel/hako_ws/cmake-build
cmake ..
make
```

### シミュレーション手順

UnityおよびROS-TCP-ENDPOINTについては，hakoniwa-ros2sim と同じで手順です．

https://github.com/toppers/hakoniwa-ros2sim/blob/main/README_jp.md#%E3%82%B7%E3%83%9F%E3%83%A5%E3%83%AC%E3%83%BC%E3%82%BF%E3%81%AE%E5%AE%9F%E8%A1%8C%E6%89%8B%E9%A0%86

TB3の制御プログラムの実行については，C++版箱庭モジュール群とOpen-ELのサンプルを起動します．
以下の順番でシミュレーションを実行します（どこかで作業の手間を減らすための対応を行います）

#### 端末A：箱庭マスタ

```
hako-master 100 1000
```

成功すると以下のメッセージが出力されます．

```
START
INFO: shmget() key=255 size=12160
```

#### 端末C：箱庭プロキシ

```
bash run.bash hako_pdu_proxy
```

成功すると以下のメッセージが出力されます．

```
START:hako_pdu_proxy_node
create_channel: id=1 size=3044
```

#### 端末D：OpenEL

```
 ./hako-openel
```

成功すると以下のメッセージが出力されます．

```
create_channel: id=0 size=48
hako_pdu_write_init(0, 48) ret=1
ActuatorHako::fncInit()
OpenEL Motor L init OK
ActuatorHako::fncInit()
OpenEL Motor R init OK
SensorHako::fncInit()
OpenEL Sensor init OK
```


#### 端末B：箱庭コマンド実行用

まずは，アセット一覧を確認してみましょう．

```
hako-cmd ls
```

以下の２個のアセットが表示されます．

```
hako_pdu_proxy_node
openel_node
```
次に，シミュレーション状態を確認してみましょう．

```
hako-cmd status
status=stopped
```

stopped となっていますので，シミュレーション停止状態です．

この状態で，Unity側のシミュレーションを開始した後，箱庭としてのシミュレーションを開始します．

```
hako-cmd start
```

シミュレーション開始するとTB3のロボットが動き出します．

### デモンストレーション

上記の一連の操作（インストール以外）の操作デモ内容です．

https://user-images.githubusercontent.com/164193/194730736-885dd449-55c0-4ce7-b280-774f7705856d.mp4




