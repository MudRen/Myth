inherit ITEM;

#include <ansi.h>

int do_kan(string arg);
void create()
{
  set_name("�����μǡ�", ({"xyj story","xyj","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("no_sell", 1);
    set("long", " �����μǡ� ���� kan �Ķ�(1-100)��\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
  object me = this_player();
  object ob = this_object();
  int size = 100;
  int nb=0;

  ob->set("value", 100);

  if (arg == "new") return 0; 

  if (! arg || sscanf(arg, "%d", nb)!=1)
  {
    write("\n");
    me->start_more(read_file("/d/obj/books-nonskill/text/xyjindex"));
    write("\n");
    write ("���� kan <number> �����й��½�(1-100)��\n");
    return 1;
  }

  if ( nb <= 0 || nb > size)
    return notify_fail ("��Ҫ����һ�£�\n");

  else 
  {  
  write("\n");
  if (nb<10 && file_size("/d/obj/books-nonskill/text/xyj0"+nb) >= 0) 
      me->start_more(read_file("/d/obj/books-nonskill/text/xyj0"+nb));
  else if (file_size("/d/obj/books-nonskill/text/xyj"+nb) >= 0)
      me->start_more(read_file("/d/obj/books-nonskill/text/xyj"+nb));
  else write("��δ���룬���Ժ�");
  write("\n");
  return 1;
  }
}

