// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

��װ����������ǽ�ϰ���һ���ŵķ�β���ȡ�������һ����
�񴰣��������������Ϲ�ǽ�·����������������Ρ����ϵ���
ױ̨ɢ�������˵���ζ��

LONG);

  set("exits", ([
        "east"   : __DIR__"hou4",
        "west"   : __DIR__"hou2",
        "south"   : __DIR__"yuhua",
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 2,
        __DIR__"npc/fakegirl"   : 1,
      ]));

  setup();
}


