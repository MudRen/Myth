// Room: some place in ��ţ����
// uphill4.c

inherit ROOM;

void create()
{
        set ("short", "������");
        set ("long", @LONG

����ĵ��Ʊ��ƽ̹��һƬ���̵Ĳ�ƺ�п��Ŷ��С������ɽ��
��ȥ�������һ������֪��������������ô���ˡ�ң��Զ����ǧ
�忪ꪣ�����������ӳ᰹������䣬������ɫ�京�ࡣ
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "east": __DIR__"guanjing",
                "northeast" : __DIR__"uphill5",
                "southwest": __DIR__"uphill3",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                "/d/lingtai/npc/qiaofu.c" : 1]));

        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

