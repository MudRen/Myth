// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����������ׯ�ϣ��������Ϻ�������磬�м���һ̴�������
����һ������λ��Ρ�����ԭ�ǿ��������ã����������վ�����
�㽫ǰ�������ˣ���Ϊ�����á�
    
LONG);

  set("exits", ([
        "northeast"    : __DIR__"shuode",
        "northwest"    : __DIR__"shien",
      ]));
  set("objects", ([
        __DIR__"npc/sg"    : 1,
      ]));
  setup();
}

