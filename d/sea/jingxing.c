inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������ķ���������ǽ�ϸ߹�һ���������ĺ����ĹŻ������е�
�����צ���ţ��ƺ�Ҫ�ӻ������������ġ������������Σ�������
һ�߼�����������ǿ���ĵط���
LONG);
         set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/biantidu" : 1,
  __DIR__"npc/lizongbing" : 1,
]));


  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"inside6",
  "northeast" : __DIR__"mulang2.c",
  "northwest" : __DIR__"shanhua.c",
]));
//      
        set("water", 1);
//  
  setup();
}

