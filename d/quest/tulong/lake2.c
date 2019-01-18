inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�����");
        set("long", HIG @LONG 
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ��һ
�����ٲ�����������������ٲ���ɽ��ֱ����£������ĺ��������
����һ���ʯ����д����������� �����ǳ��󣬴����˵�������
�����졣
LONG
        );
   set("exits", ([ 
      "northeast" : "/d/quest/tulong/lake1",   ]));

        setup();
}

void kite_notify(object obj, int i)
{
   object  me, room;
   int j;
        
   me = this_player();
   message_vision("ͻȻһ��΢�����"+obj->name()+"����������������Խ��Խ�ߡ�\n\n" , me);
   switch( random(2) ) {
   case 0:
      tell_object(me, me->name()+"���е�"+obj->name()+"Խ��Խ�ߡ� \n");
      message_vision("ֻ��һ�����õ������Ӹ߿մ����� \n", me);
      call_out("boat_come", 2, me);
   break;
   case 1:
      message_vision("һ�󾢷紵����$N���е��߶��ˣ�"+obj->name() 
+"Խ��Խ�ߣ������Ĳ����ˡ� \n",me);
      destruct(obj);
      break;
   }
   return; 
}

void boat_come(object me)
{
   object  boat, *inv, ob;
   int i;
        

   if (query("exits/down")) return ;
   if (!objectp(boat=find_object("/d/tulong/boat")))      boat=load_object("/u/night/room/boat");
   inv=all_inventory(boat);
   for(i=0; i<sizeof(inv); i++) {
      ob = inv[i];
      if(living(ob)){
         message("vision","���Σ����ϻ���û��˿��������\n",this_object()); 
         return;
      }
   }
   message("vision","���˰��Σ�һҶС�ۻ����ش����е����������˺��ߡ�\n",this_object()); 
   boat->set("exits/up","/d/quest/tulong/lake2");   set("exits/down","/d/quest/tulong/boat");   call_out("boat_leave",10,boat);
   return ;
}

void boat_leave(object boat)
{
        if (query("exits/down")) delete("exits/down");
        if (boat->query("exits/up")) boat->delete("exits/up");
        message("vision","һ��΢�������С�������˰��ߡ�\n",this_object()); 
        message("vision","һ��΢�������С�������˰��ߡ�\n",boat); 
        return;
}

int valid_leave(object me, string dir)
{
   object *inv, boat, ob;
   int i;

   if (userp(me) && dir == "down") {
      boat=find_object("/d/quest/tulong/boat");      if (!objectp(boat))
         boat=load_object("/d/quest/tulong/boat");         inv=all_inventory(boat);
            for(i=0; i<sizeof(inv); i++) {
               ob = inv[i];
               if(living(ob)){
                  tell_object(me, "��̫С�ˣ�ֻ�ܳ���һ���ˡ�\n");      
                  return notify_fail("");
               }
           }
   }
   return 1;
}


