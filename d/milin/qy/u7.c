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
       "east" : "/d/milin/qy/mishi1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/obj/drug/yanlei" : 2,
       "/d/npc/obj/spear" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
