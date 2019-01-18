inherit ROOM;
#include <ansi.h>
int do_drop(object me, object obj);
string money_str(int count);
void create()
{
 set("short","������");
        set("long", @LONG

��������������������������������������������������������������������������������
������ ��˵������Ǵ�˵�е���������ˣ�û��һ������Ϊ����û��ǲ�Ҫ�Ҵ�Ŷ ������
��������������������������������������������������������������������������������

LONG
        );
        set("exits", ([
                "up" : __DIR__"droproom",
               "down" :"/d/hellfire/gate",
        ]));
        set("objects", 
        ([ //sizeof() == 1
          "/d/city/npc/baobao" : 1,
           "/d/city/npc/nushen" : 1,
// 24            "/adm/npc/nushen" : 1,
           "/d/city/npc/shizhe" : 1,
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{
    add_action("do_stop", "bid");
    add_action("do_main", "drop");
}

int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(YEL"���ﲻ׼���������\n"NOR,who);
return 1;
}

int do_main(string arg)
{
   object me=this_player();
   object obj, *inv, obj2;
   int i, amount;
   string item;

        if(me->is_busy())
           return notify_fail("����æ���أ�����\n");
 
   if(!arg) return notify_fail("��Ҫ����ʲô������\n");

   if(sscanf(arg, "%d %s", amount, item)==2) {
     if( !objectp(obj = present(item, me)) )
        return notify_fail("������û������������\n");
     if( !obj->query_amount() )
        return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
     if( amount < 1 )
        return notify_fail("����������������һ����\n");
     if( amount > obj->query_amount() )
        return notify_fail("��û����ô���" + obj->name() + "��\n");
     else if( amount == (int)obj->query_amount() )
        return do_drop(me, obj);
     else {
        obj2 = new(base_name(obj));
        obj2->set_amount(amount);
        if(do_drop(me, obj2)) { // succeed to drop
            obj->set_amount( (int)obj->query_amount()-amount );
            return 1;
        }
        return 0;
     }
   }

   if(arg=="all") {
     inv = all_inventory(me);
     for(i=0; i<sizeof(inv); i++) {
        do_drop(me, inv[i]);
     }
     write("Ok.\n");
     return 1;
   }

   if(!objectp(obj = present(arg, me)))
     return notify_fail("������û������������\n");
   return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
   int count;
   object money;
   if(me->is_busy())
      return notify_fail("����æ���أ�����\n");
   if (obj->move(environment(me))) {
    if((obj->query_temp("d_mana"))>0) {
     if( obj->query_temp("is_living")==1 )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
     else {
       message_vision( sprintf("$N����һ%s$n��\n",   
         undefinedp(obj->query_temp("unit"))?
         "��":obj->query_temp("unit")
         ), me, obj );
     }
        } else {
     if( obj->is_character() )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
     else {
  if (obj->query("id")=="thousand-cash" || obj->query("id")=="gold"
          || obj->query("id")=="silver" || obj->query("id")=="coin")
   { message_vision( sprintf("$N����һ%s$n��\n",obj->query("unit")),me, obj );
 if(wizardp(me)) destruct(obj);}
else { message_vision( sprintf("$N��һ%s$n�ӽ������ѡ�\n",obj->query("unit")),me,obj);
     destruct(obj);
     }}
        }
       return 1;
       }
       return 0;
}
string money_str(int count)
{        
        string output;
        if (count / 10000) {
                output = chinese_number(count / 10000) + "���ƽ�";
                count %= 10000;
        }
        else
                output = "";
        if (count / 100) {
                output = output + chinese_number(count / 100) + "������";
                count %= 100;
        }
        if (count)
                return output + chinese_number(count) + "��ͭ��";
        return output;
}

// added by mudring valid pker.
int valid_leave(object me, string dir)
{
    if (pkerp(me) && dir == "down")
        return notify_fail("ͨ���ڼ䲻׼���뺮��������\n");
    return ::valid_leave(me, dir);
}
