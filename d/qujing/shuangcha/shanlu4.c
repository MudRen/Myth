//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ����һ��С�Ӻᴩ��������ˮ˳�����£����������������
·���Թ�ʯ��ᾡ�����ï�ܶ����롣
LONG);

  set("exits", ([
        "eastup" : __DIR__"on2",
        "westdown"   : __DIR__"shanlu5",
      ]));
  set("outdoors","sc");
  set("objects",([
        __DIR__"npc/taibao":1,
        ]));
  setup();
}
