//Cracked by Roath

inherit ROOM;

int _do_drop(object me, object obj);

void create ()
{
//        set ("short", "��Ʒ��������")
        set ("short", "������");
        set ("long", @LONG

����ǰ����һ��˶��������ѡ������ǳ����������ķ���ѻ�����
�л�����ʶ�ĺ�����ң�������������ӷ�����ǰ�������(drop)
����������

LONG);
/*
ʱ�ͻ�������ȴ���һ��������Ʒ�������Ÿ��ˣ���������ɢ��
����������ζ�����ﱧ�Ÿ�Ǯ�䣬���Ǳ���Ʒվ�Ĵ�ʹ����ħ(devv)��
ÿ��һ����Ʒ�����������һ��ͭ�������͡�

LONG);

*/
  set("no_magic",1);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 1
                "up" : __DIR__"center",
        ]));

        setup();
}

void init() {
  add_action("do_drop","drop");
}

int do_drop(string arg)
{
        object money,obj, *inv;
        int i,reward=0;
        string item;
         
        object me=this_player();

        if(me->is_busy())
           return notify_fail("����æ���أ�����\n");
 
        if(!arg) return notify_fail("��Ҫ����ʲô������\n");

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                      reward+= _do_drop(me, inv[i]);
        } else {
            if(!objectp(obj = present(arg, me)))
                  return notify_fail("������û������������\n");
            reward+= _do_drop(me, obj);
        }
  reward=0;
        if (reward) {
          seteuid(getuid());
          money=new("/obj/money/coin");
          money->set_amount(reward);
          if (money->move(me))
             write("��õ���"+chinese_number(reward)+"öͭ��ĳ��͡�\n");

    }
        return 1;
}

int _do_drop(object me, object obj)
{
   if (!obj->move(this_object())) return 0;
    if((obj->query_temp("d_mana"))>0) {
       if( obj->query_temp("is_living")==1 )
            message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
       else  message_vision( sprintf("$N����һ%s$n��\n", 
              undefinedp(obj->query_temp("unit"))?
              "��":obj->query_temp("unit")
              ), me, obj );
        return 0;          
    } 

   if( obj->is_character() ) {
       message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
       return 0;
   }
   message_vision("$N��$n�ӽ������ѡ�\n", me, obj );
   destruct(obj);
   return 1;
}

