// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target, item;
        object obj, dest, *inv, obj2;
        int i, amount;

        if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲô������\n");

        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) )
                return notify_fail("����û������������\n");


        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( obj->query("no_give") || 
                        obj->query("no_drop") || obj->query("no_get") )
                        return notify_fail( "Ok.\n" );
                
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_put(me, obj, dest);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if(do_put(me, obj2, dest)) { // failed to put.
                            obj->set_amount((int)obj->query_amount()-amount);
                            return 1;
                        } else return 0;
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)  {
                        if( inv[i]->query("no_give") || 
                                inv[i]->query("no_drop") || inv[i]->query("no_get") )
                                        continue;

                        if( inv[i] != dest ) do_put(me, inv[i], dest);
                }
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("������û������������\n");
        if( obj->query("no_give") || 
                obj->query("no_drop") || obj->query("no_get") )
                return notify_fail( "Ok.\n" );
        return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
        object* inv;
        int             amount;
/*
        if( userp(dest) )  {
        inv = all_inventory(dest);
                if( sizeof(inv) > 30 )
                   return notify_fail("�Է�������Ҳװ�����κζ����ˡ�\n");
        }
        else if( !dest->is_character() && dest->is_container() )   {
        inv = all_inventory(dest);
                if( !(amount=dest->query("max_items")) )   amount = 5;
                if( sizeof(inv) >= amount )
                   return notify_fail(dest->name()+ "����Ҳװ�����κζ����ˡ�\n");
        }
*/
        
        if(!dest->is_character() &&
                !dest->is_container())
            return notify_fail("�㲻�ܰ�"+obj->name()+
                    "�ŵ�"+dest->name()+"��ȥ��\n");
       if (obj->query("rumor_announce"))
                        return notify_fail("�뷨��������û�á�\n");                       

        if( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
                if(wizardp(me))
                 log_file("cmds/wiz_put",sprintf("%s��һ%s%s�Ž�%s(%s)��\n",me->query("id"),
                        obj->query("unit"), obj->name(), dest->name(),ctime(time())));  
                return 1;
        }
        else return 0;
}

int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
