// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��");
  set ("long", @LONG

���ſ��������Ųʵƣ����ڻ��н���˫��Ϸˮ���ڱڴ���һ��ʯ
���磬���������ױ̨��һ�����봲�졣���ϳ�����һ���ţ��ɼ�
λ��Ů�غ��š�

LONG);

  set("exits", ([ 
    "southeast" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nuyao" : 2,
    __DIR__"npc/queen" : 1,
  ]));
  setup();
}
