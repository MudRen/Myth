//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������ǻ��ƶ������ģ������á���ǰ��һ�Ѻڻ�Ƥ�����θ߸�
���ϣ��κ�һ����ɫ����죬�������š�ʥӤ�������ĸ����ӡ�
����С��������ͷ����ʮ�����͵ư������յ�ѩ����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao7",
  "west" : __DIR__"jin",
  "east" : __DIR__"tu",
  "northeast" : __DIR__"huo",
  "northwest" : __DIR__"mu",
  "north" : __DIR__"shui", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/honghaier" : 1,
  __DIR__"obj/che1" : 1,
  __DIR__"obj/che2" : 1,  
  __DIR__"obj/che3" : 1,  
  __DIR__"obj/che4" : 1,  
  __DIR__"obj/che5" : 1,  
]));


  setup();
  
//   call_other("/obj/board/kusong_b", "???")
}


