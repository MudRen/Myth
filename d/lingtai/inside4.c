// Room: some place in ��ţ����
// inside4.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

��˵��ʿ����赭���ԵĲ����ã�������ȴ�����ܼø���һЩƶ
��Ĵ��񣮱��ϵļ����϶����߲ˣ�һ�ڴ�ˮ������ǽ�ǣ�һ��
���ֵĵ�ʿ�����ջ�¯���������ڣ���֪���ʲô�������Ҫ
Щ(yao)�Եġ�
LONG);

        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"houyuan",
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
                "bowl" : "�������������ڵİ��ӣ���Ҫ����Ҳ������Щȥ�ԣ�",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/wanfeng" : 1,
                "/d/ourhome/obj/hulu" :1,
        ]));
        set("clean_up", 1);
        set("resource", ([ /* sizeof() == 1 */
                "water" : 1,
        ]));

        setup();
}
int valid_leave()
{
        if((present("bao zi", this_player())))
                return notify_fail("�������������\n");
        if((present("hulu", this_player())))
                return notify_fail("�㲻�ܰѺ�«���ߣ�\n");
        return ::valid_leave();
}

