// hill.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������Ƕ��������д󽫾����޵еİ칫������̴ľ���ϲ������졡����
�������ƽ����Ϻ��з���ǲ���������ģ��������ҲС������������
���Ҵ�����������Χһ�����µ����ա�

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yujie2.c",
  "north" : __DIR__"jingxing.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jing" : 1,
]));
//      
        set("water", 1);
//  
        setup();
}

