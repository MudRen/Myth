//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "������");
        set("long", @LONG

���������һ�,������������,�������ڻ�����кú�˯һ��.
LONG
        );
        
        set("exits", ([
                "east": __DIR__"tao_in",
            ]));
	set("objects",([
		__DIR__"obj/guo" : 3,
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
  write("����һ����Ʈ��,�㷭����ȥ����Ҳ˯���š�\n");
  this_player()->start_busy(random(2));
  return 1;
}

