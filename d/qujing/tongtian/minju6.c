// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����˼�Ҳ�ǳ��գ���������Ŵ�С����ɹޣ��������Ż���
֮��Ķ������ϱߵ����ȴ��Ӵ󿪣�������Ʈ��һ�ɻ��ݵ���
��ζ��

LONG);

  set("exits", ([
        "out"   : __DIR__"chen3",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+2,
        __DIR__"npc/kid"  : random(1)+1,
      ]));

  setup();
}



