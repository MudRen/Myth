// Room: some place in ��ţ����
// forrest2.c

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
                "north" : __DIR__"forrest",
                "south" : "/d/quest/m_weapon/liangunshi",

        ]));
        set("objects", ([ /* sizeof() == 2 */
                "/d/lingtai/obj/shuzhi": 2]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{       if (dir == "north"&&"south"&& me->query("kanchai") )
        me->delete("kanchai"); 
        return 1;
}

