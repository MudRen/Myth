// Room: some place in ��ţ����
// gelou.c

inherit ROOM;

void create()
{
        set ("short", "��¥");
        set ("long", @LONG

�����Ǿ���ĸ�¥������ʮ�ּ��ӣ�һ��ľ������������
��ǽ��һ��̴ľ�������ᴹ��ľ���ϰڷ���һЩ���ҵ伮
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "down": __DIR__"lou",
        ]));
        set("objects", ([
                __DIR__"npc/sanxing": 1 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

