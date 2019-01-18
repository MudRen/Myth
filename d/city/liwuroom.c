// Room: /d/liwu/lipinroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "������Ʒ��");
        set("long",
"����һ���������С���ӣ���Ӵ���������ȥ����������������ʵƣ�\n"
"�����������ա���������һ�������де������������������õ�������˶�Ц�����գ�\n"
"�Ͽ��ȥ��һ���ɣ� \n\n"
HIC"��� �������㣮���㣮���� ���㣮��㣮� �㣮�������\n"NOR
HIC"��� �������㣮���㣮���� ���㣮��㣮� �㣮�������~~~ \n"NOR
HIW"  ~~~~\    ��            ^*^          "+HIR".��\n"NOR
HIW"   ./  \~~~��~   ~~~~\ ��             "+HIR"$����$\n"NOR
HIW"   / ^^ \ �T�T�T�T�T�T              "+HIR"$���﨎$"+HIG"        Happy\n"NOR
HIW" ..��[]  ����  �� �� |            "+HIR"$��������$"+HIG"             New\n"NOR
HIW" ����    ��       ��'|'��       "+HIR" $����������$"+HIG"                Year ��\n"NOR
HIW"�� �����������������������{�z�y�x "+HIR"���||���\n\n"NOR
);

        set("exits", ([
                
               "north" : "/d/wiz/entrance",
        ]));
        set("no_time",1);
        set("no_fight", 1);
        set("no_spells", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */

       "/u/hanhan/meng/obj/tree" : 1
      ]));


        setup();
                call_other( "/obj/board/sanjie_meiwen", "???" ); 
//        replace_program(ROOM);
}

void init()
{
    add_action("do_drop", "drop");
    add_action("do_drop", "get");
}

int do_drop()
{
    tell_object(this_player(),"�����������ʲô��\n");
    return 1;
}
