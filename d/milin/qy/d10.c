// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "���ֱ���");
        set ("long", @LONG
    ���������ֵ������ܵĵط�---���ֱ���,��˵����ı���
����Ů����������ʹ����,���Ǻ���һֱû��ô�ù�,�վ��쳤
Ҳ��������Щ�����Ĵ��ڡ�
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "out" : "/d/milin/qy/mishi2",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/moon/obj/xuelian" : 3,
       "/d/npc/obj/xiuhuaxie" : 1,
        "/obj/money/gold" : 3,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
