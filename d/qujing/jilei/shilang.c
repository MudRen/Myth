//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ʯ���ＫΪ�����Ӷ��������³���������ʯ�������д�Сʯ
��������Ȼ���ɵ����Ρ�ʯ�ȵ����������й��ߴӶ����������
ʯ�ȵ���������һ��������


LONG);

  set("exits", ([
        "northwest"   : __DIR__"shidong",
        "southwest"   : __DIR__"dating",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
      ]));

  setup();
}



