//make.c

#include <ansi.h>

void done(object me);
int main(object me, string str)
{
/*
        object ob;
        int lv;
        lv=me->query_skill("medical",1);

        seteuid(getuid());

        if( me->is_busy() )
        return notify_fail("����æ���ء�\n");

        if( !arg )
        return notify_fail("��Ҫ��ʲôҩ��\n");

        if( me->is_fighting() )
        return notify_fail("������ս������ʲôҩ����\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("����æ���أ�ûʱ����ҩ��\n");

     switch (arg)
      {
      case "jinchuang":
        if( ! present("tian qi", me) || ! present("gou gu", me) )
        return notify_fail("���ҩ�Ĳ���ȫ��\n");
        if( lv < 1 )
        return notify_fail("���ҽ�������Ƴ���ҩ��\n");
done(me);
        ob=new("/obj/jineng/medical/jinchuang.c");
        ob->move(me);
        me->start_busy(3);
        break;

        default:   notify_fail("��û������������ҩ��\n");
        
*/
object ob1,ob2,ob3;
string st1,st2;
if (!str || str=="")  
return notify_fail ("����ϲ�ʲôѽ\n");
if (sscanf( str,"%s and %s",st1,st2)!=2 )
return notify_fail ("make <��Ʒ> and <��Ʒ>\n");
if( !objectp(ob1 = present(st1,this_player())) ) 
return notify_fail("��û�� "+st1+" ������Ʒ.\n");
if( !objectp(ob2 = present(st2,this_player())) ) 
return notify_fail("��û�� "+st2+" ������Ʒ.\n");
  if( (!ob1->query("food_remaining")) && (!ob2->query("armor_prop")))
return notify_fail("�����Ʒ���ܺϲ���\n"); 
if ((!ob1->query("armor_prop")) || (!ob2->query("food_remaining")))
return notify_fail("�����Ʒ���ܺϲ���\n"); 
if( ob3=new("/d/qujing/tianzhu/obj/fen.c")){
destruct(ob1); 
destruct(ob2); 
ob3->move(this_player());
message_vision(HIW "$N��Ʒ���ɣ�һ���ǽ�Ƿ�\n" NOR,this_player()); 

        }

        return 1;
}


void done(object me)
{
        int i;
        object *inv; 
               inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("done"))
                        destruct(inv[i]);
                }
message_vision( HIC "ֻ��$N��������ҩ��֮�ϣ������ҩ�ı���ʧ�ˡ�\n" NOR,me);
                me->start_busy(6);
return;
}

