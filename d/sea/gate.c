// gate.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

Ƕ�ڹ���������䱦�����Ĺ�âҫ�������۾����������ˡ���ϡ��������
�������Ϸ�����һ�����ң����У������������ĸ����֡�����Ϻ��������
з���������ԣ�����Ķ����������ˡ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"under4",
  "east" : __DIR__"inside1",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/soldier1" : 2,
  __DIR__"npc/soldier2" : 2,
]));
//      
        set("water", 1);
//  
        setup();
}

