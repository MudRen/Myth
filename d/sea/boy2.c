// boy2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����������ȣ�������ǰ������������̫�ӵ����ң��������꽻��
��������������Ů���ź���������ȥ������һ���������̫�������
�ط���

LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gongnu" : 2,
]));
  set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"boy1",
  "north" : __DIR__"boy4",
  "east" : __DIR__"boy3",
]));
//      
        set("water", 1);
//  
        setup();
}

