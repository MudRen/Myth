// Room: some place in ��ţ����
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "����ɽ");
  set ("long", @LONG

������һƬҰ���֣�ɽ�е��������˲�ժ�����ܵ����ӹ���֦
ͷ�����µ����Ѹ��ó��࣬��֪�Ѽ��˼����ꡣ
LONG);
set("exits", ([ /* sizeof() == 4 */
"eastdown" : __DIR__"lantao",

]));
//
//set("objects", ([ /* sizeof() == 2 */
//"/d/lingtai/obj/shuzhi": 2]));
//  
      set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


