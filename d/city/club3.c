//Cracked by Roath
// Room: /d/city/club3
inherit ROOM;

int do_look();
void reset_long();

string long=@LONG

����һ��������Ĵ������������м���һ��Բ�ε����ӡ���������
���˸��ֹ�棺�л����ģ������Ҿߵģ����������Ļ����Ҵ��ƴ�
���Ĺ�档���Ķ����������и��ţ����洫�����������������ˣ���
�ȵĽ�����
LONG;

void create ()
{
  set ("short", "������");
  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"piggy_e",
  "south": __DIR__"piggy_s",
  "west": __DIR__"piggy_w",
  "north": __DIR__"piggy_n",
  "down" : __DIR__"clubup",
  "up" : __DIR__"clubpoem",
]));

  set("objects", ([ 
	    __DIR__"npc/pig_counter" : 1,
  ]));

  setup();
  call_other("/obj/board/zhuzi_b", "???");
  reset_long();
}

object find_pig_counter()
{
    object *list = filter_array(children(__DIR__"npc/pig_counter"), 
	    (:clonep:));
    object obj;
    
    if(sizeof(list)==0) {
	seteuid(getuid());
	obj=new(__DIR__"npc/pig_counter");
	obj->move(this_object());
	return obj;
    } else
	return list[0];
}

int do_look()
{
    reset_long();
    return 0;
}

void reset_long()
{
    object pig=find_pig_counter();
    set("long",long+"\n"+pig->pig_bang());
}
