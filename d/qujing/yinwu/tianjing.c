// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�쾮");
  set ("long", @LONG

������쾮�����ľͷ���ż��ӣ������ϴ���һЩ��Ƥ����
����һЩ������Ĵ�ʯ�飬����ɹ������ӡ��쾮��һ�Ƕ���
һЩ��ͷ��

LONG);

  set("exits", ([
        "west"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoyao" : 3,
        __DIR__"npc/feimayi" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

