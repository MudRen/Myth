// give.c
#include <ansi.h>
inherit F_CLEAN_UP;

mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return HIR"��Ʒ����(Give)";
    return 0;
}


int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target, item;
        object obj, who, *inv, obj2;
        int i, amount, rev_val;
        mixed no_give;

    if(this_player()->is_busy())
           return notify_fail("����æ���أ�����\n");
                                 
        if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

        if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
        else return notify_fail("��Ҫ��˭ʲô������\n");

        if(!objectp(who = present(target, environment(me))) || !living(who))
                return notify_fail("����û������ˡ�\n");

        if( me == who )  {
                write("Ok.\n");
                return 1;
        }


        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) ) 
                        return notify_fail("������û������������\n");
        if(!wizardp(me)) 
              {
                if( no_give=obj->query("no_give") )
                        return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");
              }
                if( obj->query("obj_owner"))
                        return notify_fail("������������������ˡ�\n");
                if( !obj->query_amount() )      
                        return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() ) 
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_give(me, obj, who);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        rev_val = do_give(me, obj2, who);
                        if( rev_val == 2 )
                           obj->set_amount( (int)obj->query_amount() - amount );
                    else
                           destruct(obj2);
                        return rev_val; 
                }
        }

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("no_get")) continue;
                        do_give(me, inv[i], who);
                }
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("������û������������\n");
        if(!wizardp(me)) 
              {
        if( no_give=obj->query("no_give") )
                return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");
            }
        return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
        int   is_accept;
        object  *inv;
        mixed no_give;
      
    if(me->is_busy())
           return notify_fail("����æ���أ�����\n");
    
    if(who->is_busy())
           return notify_fail("�Է���æ���أ�ûʱ�����㣮����\n");
// no_accept should be in do_give Bula    
    if(who->query("env/no_accept") && !is_root(me) )
           return notify_fail("�Է�����Ը��������Ķ�����\n");

        if(no_give=obj->query("no_give") && !wizardp(me) )
                return notify_fail( stringp(no_give) ? no_give : "���������������ⶪ����\n");
/*
        inv = all_inventory(who);
        if( sizeof(inv) > 30 )
           return notify_fail("�Է�������Ҳװ�����κζ����ˡ�\n");
*/
        // snowcat jan 23 1998
        if( !interactive(who)) {
                if (QUEST->quest_give (me, who, obj)) {
                        message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n",me,who);
                        message_vision("$N���Ե���$n��л��\n",who,me);
                        me->start_busy(2);
                        destruct(obj);
                        return 1;
                } 

      
   if (QUEST->quest_reward (me, who, obj)) {
                     message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n",me,who);
                        message_vision("$N���Ե���$n��л��\n",who,me);
                        me->start_busy(2);
                        destruct(obj);
                        return 1;
                }


                if( !(is_accept=who->accept_object(me, obj)) )
                        return notify_fail("�Է���Ҫ��Ķ�����\n");
                if( is_accept == 2 )
                        return 1;
               

        }

        if( !userp(who) && obj->value() ) { // give money to npc
                message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
                destruct(obj);
                return 2;
        } else if( obj->move(who) ) {
                string unit;
                if(obj->query_temp("d_mana")>0)
                  unit=obj->query_temp("unit");
                else
                  unit=obj->query("unit");
                if(strlen(unit)<2) unit="��";
                printf("���%sһ%s%s��\n", who->name(), unit,
                        obj->name());
                message("vision", sprintf("%s����һ%s%s��\n", me->name(),
                        unit, obj->name()), who );
                message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
                        unit, obj->name()), environment(me), ({me, who}) );
                if(!userp(who) && !userp(obj)) destruct(obj); // mon 4/25/98
               //added by hawks 2000.12.10
                if (wizardp(me)&& userp(who)&&!wizardp(who)
                &&(!is_root(me)||me->query("env/wizset")!="give")) {
                    log_file( "static/GIVE_PLAYER", sprintf("(%s) %s give %s to %s\n", ctime(time()), 
                          me->query("id"), obj->query("name"),who->query("id")));
    CHANNEL_D->do_channel(this_object(),"chat",
                        sprintf("����%s(%s)����%s(%s)һ%s%s(%s) \n",
                                me->query("name"), me->query("id"), who->query("name"), who->query("id"), unit, obj->query("name"), obj->query("id")) );
    CHANNEL_D->do_channel(this_object(),"sys",
                        sprintf("%s(%s)����%s(%s)һ%s%s(%s) \n",
                                me->query("name"), me->query("id"), who->query("name"), who->query("id"), unit, obj->query("name"), obj->query("id")) );


               }
              // add end     
                return 2;
        }
        else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.

������ʱ : set no_accept <����ֵ>
���½��� : unset no_accept
HELP
    );
    return 1;
}

