inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰���
�󵶡��������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һ
ʱ��֪����ʲô�á�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"bingying",
        ]));
        set("objects", ([
                "/d/obj/weapon/sword/changjian" : 2,
                "/d/obj/weapon/blade/blade" : 2,
                "/d/obj/weapon/dagger/dagger" : 2,
                "/d/obj/weapon/stick/bintiegun" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

