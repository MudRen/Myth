// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        
	set("exits", ([
                "out": "/d/changan/playerhomes/h_tingting",
            ]));
	set("sleep_room",1);
	set("if_bed",1);
                                              
        setup();
}
void init()
{
object me = this_player();
string id;

if (getuid(this_player()) != "dream"
&& getuid(this_player()) != "tingting") {
me->move("/d/changan/phomes");
message_vision("$N�ƺ�����һ�����˳�������ɫ�е��Ǳ���\n", me);
}
}



