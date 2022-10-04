# hakoniwa-openel

## 概要

箱庭上で TurtleBot3 を制御する Open-EL サンプルプロジェクトです．

## ソースコード

箱庭上で動作する Open-EL サンプルアプリはこちらの main 関数です．

https://github.com/tmori/hakoniwa-openel/blob/main/ros_ws/src/openel_node/src/main.cpp

また，箱庭上で動作可能な Open-ELデバイスソース一式はこちらです(ROS2ベース)．

https://github.com/tmori/hakoniwa-openel/tree/main/ros_ws/src/openel_node/src/openel

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


## Open-EL側のビルド手順

docker コンテナの端末を以下の手順でもう１個起動します．

```
bash docker/attach.bash
```

docker コンテナ上で，Open-EL 側のビルドを行います．

```
cd /root/workspace/openel/ros_ws/src
bash build.bash
```

## シミュレーション手順

シミュレーション手順は，基本的に，hakoniwa-ros2sim と同じです．

https://github.com/toppers/hakoniwa-ros2sim/blob/main/README_jp.md#%E3%82%B7%E3%83%9F%E3%83%A5%E3%83%AC%E3%83%BC%E3%82%BF%E3%81%AE%E5%AE%9F%E8%A1%8C%E6%89%8B%E9%A0%86

ただし，TB3の制御プログラムの実行は，Open-ELのサンプルを使います．
そのため，Open-ELをビルドした docker コンテナ/ディレクトリ直下で以下のコマンドを実行してください．

```
bash run.bash openel_node TB3RoboModel
```

