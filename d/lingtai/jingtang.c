// Room: some place in ��ţ����
// jingtang.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

���������Ƕ��Ľ����ã�ƽʱ��ʿ�Ǳ������ｲ��˵��������
��ʲô���£�Ҳ�����Ｏ�����顣������������ط�������ʮ
����棬Ҳ����һ��ʮ����ʿ��
LONG);

        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"houlang1.c",
                "southdown" : __DIR__"inside1.c",
                "east" : __DIR__"siyuan.c",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/xiao" : 2,
        ]));
        setup();
}

