//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "�޹Ǵ���");
        set("long", @LONG

һ�����޹Ƕѻ������Ĵ�������������һ����Ƥ����ǿ����˯
����

LONG
        );
        
        set("exits", ([
                "out": __DIR__"woshi",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
//      set("objects", ([ "d/obj/drug/wudiguo": 10 ]) );
        setup();
}
