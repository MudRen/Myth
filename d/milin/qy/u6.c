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
       "west" : "/d/milin/qy/mishi1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/obj/drug/hunyuandan" : 10,
       "/d/npc/obj/mace" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
