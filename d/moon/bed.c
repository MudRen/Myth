//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "���������");
        set("long", @LONG

һ������ɫ����齣�����ܵ�����Ҷ�񣬿���ȥ��Ϊ���£�ɴ
��ԧ��֮��ɢ����һ˿˿���㣮
LONG
        );
        
        set("exits", ([
                "out": __DIR__"bedroom",
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
  if (this_player()->query("family/family_name")=="�¹�") return 0;
  write("���뵽�������϶�����ң��˷ܵ����۷��⣬������ȥ����Ҳ˯���š�\n");
  this_player()->start_busy(random(3));
  return 1;
}

