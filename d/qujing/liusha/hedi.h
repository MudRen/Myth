#include <ansi.h>

void init()
{
        object me=this_player();
        if( interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",2+random(4), me);
        }
        return;
}

int greeting(object me)
{
   object *list, ob;
   int i;
   if( !me || environment(me) != this_object() ) return 1;
   tell_room(this_object(), HIR"��Ȼһ��������������Ҳ����ס�ţ�˲�䣬�㱻�����������޵���Ԩ�����������в����³�\n"NOR);
   list=all_inventory(this_object());
   i=sizeof(list);
   while (i--)
   {
     ob=list[i];
     ob->move(__DIR__"dong");
     message_vision("ֻ��$N��һ�ɾ޴��ˮ�����˽�����\n", ob);
     ob->add("sen",-50);
   }
   return 1;
}
