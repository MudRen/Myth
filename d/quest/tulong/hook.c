inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("С����", ({ "hook" , "gou zi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��СС�Ĺ��ӣ�������������������Ĺ��ӣ�Ҳ���������
������һ������ˡ�(make) \n");
                set("value", 10);
        }
}

void init()
{
   if(this_player()==environment())
   add_action("do_make", "make");
}

int do_make(string arg)
{
   int i,xxan=0,taozhi1=0;
   object fpole, me, xan, taozhi, *inv;

   me = this_player();
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
      if(inv[i]->query("name") == "ϸ����") {xxan=1; xan = inv[i];}
      if(inv[i]->query("name") == "��֦") {taozhi1=1; taozhi = inv[i];}
   }
   if ( xxan && taozhi1)
   {
      destruct(xan);
      destruct(taozhi);
      fpole = new(__DIR__"fpole");
      fpole->move(me);
      message_vision("$N�����ɵ�˫�������һ�����µ�С��ˡ�\n", me);
      destruct(this_object());
   }
   else
      message_vision("$N��Ū�������ϸ���ߡ�\n", me);
   return 1;
}






