// mon 10/10/98 

inherit ROOM;

#define OUTROOM __DIR__"exit"

void create ()
{
  set ("short", "�ݹǶ�");
  set ("long", @LONG

��Χ��ɭ�ڰ���ֻ�б�صİ׹Ǵ��м����һ����İ���
ӫ����˸��������΢���Ĺ������㷢���Լ�������һ����
�ύ����Ӵ�Ѩ֮�С�

LONG);

  set("objects", ([
//        __DIR__"npc/yaomo"  : random(2),
      ]));
  
  if(random(3)==0) {
      object sheli;
      seteuid(getuid());
      sheli=new(__DIR__"obj/shelizi");
      sheli->set_amount(1+random(5));
      sheli->move(this_object());
  }

  set("cave",1);
  set("no_magic",1);
  set("no_move", 1);
  set("no_cron", 1); // mudring.
  setup();
}

void init()
{
    add_action("do_void","cast");
    add_action("do_void","exert");
}
int do_void(string arg)
{
        return 1;
}

int clean_up ()
{
  return 0;
}
