//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "ǧ�꺮����");
        set("long", @LONG

һ��ǧ�꺮�����ɵ�С������˵��������ڹ���������.
LONG
        );
        
        set("exits", ([
                "out": __DIR__"shishi3",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}
void init() {
  add_action("do_sleep","sleep");
  ::init();
}
int do_sleep() {
  if (this_player()->query("family/family_name")=="��˿��") return 0;
  write("�㶳��ȫ����,������ȥ����Ҳ˯���š�\n");
  this_player()->start_busy(random(3));
  return 1;
}

