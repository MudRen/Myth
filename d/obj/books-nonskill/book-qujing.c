inherit ITEM;

#include <ansi.h>
#include </d/qujing/obstacle.h>

int do_read(string arg);
void create()
{
  set_name("�����μ�������ȡ�澭ָ�ϡ�", ({"xyj qujing","xyj","qujing","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("no_sell", 1);
    set("long", " �����μ�������ȡ�澭ָ�ϡ� ���� read �Ķ���\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me = this_player();
  object ob = this_object();
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *chapters = values(obstacles);
  int i, nb=0;

  chapters = (string *)sort_array (chapters, 1);
  ob->set("value", 0);

  if (arg == "new") return 0; 
//::read();

  if (! arg ||
      sscanf(arg, "%d", nb)!=1)
  {
    write ("���μ������������������\n");
    for (i = 0; i < size; i++)
    {
      write ("  "+chapters[i]+"\n");
    }
    write ("���� read <number> �����йص�����\n");
    return 1;
  }

  if ( nb < 1 || nb > size)
    return notify_fail ("��Ҫ����һ������\n");

  nb--;
  for (i = 0; i < size; i++)
  {
    if (obstacles[names[i]] == chapters[nb])
    {
      nb = i;
      break;
    }
  }

  write("\n");
  me->start_more(read_file("/d/qujing/"+names[nb]+"/"+names[nb]));
  write("\n");
  return 1;
}

