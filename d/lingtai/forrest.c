// Room: some place in ��ţ����
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

����֮�зǳ��İ�������ȫ����ɡ��ǵ���֦��ס����Χ��
����һ����Ӱ����ֻ������������һ�����ߣ����˽��µĿ�
֦�������ȶ�ʱ�ĲҽУ�ֻ��һЩ���ĵ�С�����ĵĽ��ţ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"lantao1",
"south" : __DIR__"forrest2",
"east" : __DIR__"uphill2",
"west" : __DIR__"cave1",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 2]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


