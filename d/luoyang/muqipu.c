inherit ROOM;

void create()
{
        set("short", "³��ľ����");
        set("long", @LONG
����һ��ר��ľ����С�꣬���治��ȴ�����ࡣ����ľ��������Щ
ľ����ľǹ֮�࣬³�ϰ�Ҳ�����й䣬�������¡���˽����˵�������洫
���գ�ȷ˭Ҳû������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sroad7",
        ]));
        set("objects", ([
                __DIR__"npc/lu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

