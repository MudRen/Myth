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
        "east"   : __DIR__"hou3",
        "west"   : __DIR__"hou1",
        "south"   : __DIR__"long",
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 2,
      ]));

  setup();
}


