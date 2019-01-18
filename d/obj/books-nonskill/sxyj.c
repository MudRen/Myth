inherit ITEM;

#include <ansi.h>

int do_kan(string arg);
void create()
{
  set_name("�����μǼ�д����", ({"xyj story","xyj","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("no_sell", 1);
    set("long", " �����μǼ�д���� ���� kan �Ķ�(0-46)��\n");
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
  int size = 46;
  int nb=0;

  ob->set("value", 0);

  if (arg == "new") return 0; 

  if (! arg || sscanf(arg, "%d", nb)!=1)
  {
    write("\n");
    me->start_more(read_file("/d/obj/books-nonskill/sxyj/0"));
    write("\n");
    write ("���� kan <number> �����й��½�(0-46)��\n");
    return 1;
  }

  if ( nb < 0 || nb > size)
    return notify_fail ("��Ҫ����һ�£�\n");

  else 
  {  
  write("\n");
//  write("/d/obj/books-nonskill/sxyj/"+nb);
  me->start_more(read_file("/d/obj/books-nonskill/sxyj/"+nb));
  write("\n");
  return 1;
  }
}

