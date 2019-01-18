// buy.c
#define FAMILYD "/adm/daemons/familyd"
#define SHILI_D "/adm/daemons/shili"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string item, targ;
        object ob, owner;
        int price, afford;
        string fname,opfaname,faname=me->query("family/family_name");
        string* slist;

        if( this_player()->is_busy() )
                        return notify_fail("��������æ���ء�\n");

        if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
                return notify_fail
("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

        if( !objectp(owner = present(targ, environment(me))) )
                return notify_fail("��Ҫ��˭������\n");

           if( userp(owner) ) {
                message_vision("$N����$n����" + item + "����\n", me, owner);
                notify_fail("�Է�����Ը����㽻�ס�\n");
                return 1;
        }
        
        if( (price = owner->buy_object(me, item)) == -1 ) return 1;
        if( price < 1 ) return 0;

        fname=file_name(environment(me));
        slist=explode(fname,"/");
        opfaname=SHILI_D->query_family(slist[sizeof(slist)-2]);
        if((opfaname!="")&&(opfaname==faname)){
       message_vision("$n��$N˵�����ڹ����Ѿ������չˣ����ھͲ�����.\n",me,owner);
      price=price;
        }
        if((opfaname!="")&&faname&&(FAMILYD->family_relation(opfaname,faname)==-1)){
                message_vision("$n��$N˵��"+SHILI_D->query_master(opfaname)+"˵�ˣ����������ɵ��ӵĶ������۸�Ҫ������\n",me,owner);
                price=price*2;
        }
        
        if( afford = me->can_afford(price) ) {
          if( afford==2 ) 
                           return notify_fail("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");

                if(owner->complete_trade(me, item)) {
                  me->pay_money(price);
                  return 1;
                } else {
                    return 0;
                }
        } else
                return notify_fail("���Ǯ������\n");
}

int help(object me)
{
   write( @HELP
ָ���ʽ: buy <something> from <someone>

��һָ��������Դ�ĳЩ����������Ʒ��
HELP
   );
   return 1;
}
