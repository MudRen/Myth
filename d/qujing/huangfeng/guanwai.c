// created by angell 1/1/2001
// room: /d/qujing/huangfeng/guanwai.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ô˴��ѷǴ�����ء�������ȥֻ��Ⱥɽ���࣬һ����·
������Ⱥɽ����֮�䡣�������˼����ؾ��Ǵ��ƹ��ˡ�����
��Ρ����ΰ������һ�򵱹أ����Ī�������ơ�

LONG);
 
  set("exits", ([
        "east"      : "/d/westway/jiayu",
        "southwest"   : __DIR__"shanlu1",
      ]));

  set("outdoors", __DIR__);

  setup();
}


