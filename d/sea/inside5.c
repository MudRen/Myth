inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������������ܸ����ûʣ��ϱ��Ƕ������ޣ��������������б�
�����Σ�������һ�Ű��񴰣������ϵ��Ž������ͼ���������̻�
��ͨ�����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gui" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qingxin.c",
  "north" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
        setup();
}

