//make.c

#include <ansi.h>

void done(object me);
int main(object me, string arg)
{
      object ob,ob1,ob2; 
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
/*
        if( lv < 1 )
        return notify_fail("���ҽ��������ҩ��\n");
*/
     switch (arg)
      {
      case "lingdan":
         if( ! present("niu huang", me) || ! present("ren shen", me) )
        return notify_fail("���ҩ�Ĳ���ȫ��\n");
          ob1 = present("niu huang",this_player());
          ob2 = present("ren shen",this_player());
         ob=new("/d/kaifeng/obj/dan.c");
        ob->move(me);
        me->start_busy(3);
        destruct(ob1); 
        destruct(ob2); 
done(me);
        break;
case "�ⶾ��1":
if( ! present("san qi", me) || ! present("ren shen", me) )
return notify_fail("���ҩ�Ĳ���ȫ��\n");
ob1 = present("san qi",this_player());
ob2 = present("ren shen",this_player());
ob=new("/obj/jineng/medical/jinchuang.c");
ob->move(me);
me->start_busy(3);
destruct(ob1); 
destruct(ob2); 
done(me);
break;

case "�ⶾ��2":
if( ! present("san qi", me) || ! present("gouji zi", me) )
return notify_fail("���ҩ�Ĳ���ȫ��\n");
done(me);
ob1 = present("san qi",this_player());
ob2 = present("gouji zi",this_player());
ob=new("/obj/jineng/medical/jinchuang.c");
ob->move(me);
me->start_busy(3);
destruct(ob1); 
destruct(ob2); 
done(me);
break;
case "�ⶾ��3":
if( ! present("san qi", me) || ! present("niu huang", me) )
return notify_fail("���ҩ�Ĳ���ȫ��\n");
ob1 = present("san qi",this_player());
ob2 = present("niu huang",this_player());
ob=new("/obj/jineng/medical/jinchuang.c");
ob->move(me);
me->start_busy(3);
destruct(ob1); 
destruct(ob2);
done(me);
break;
case "�ⶾ��4":
if( ! present("gouji zi", me) || ! present("niu huang", me) )
return notify_fail("���ҩ�Ĳ���ȫ��\n");
ob1 = present("gouji zi",this_player());
ob2 = present("niu huang",this_player());
ob=new("/obj/jineng/medical/jinchuang.c");
ob->move(me);
me->start_busy(3);
destruct(ob1); 
destruct(ob2); 
done(me);
break;
case "�ⶾ��5":
if( ! present("gouji zi", me) || ! present("ren shen", me) )
return notify_fail("���ҩ�Ĳ���ȫ��\n");
ob1 = present("gouji zi",this_player());
ob2 = present("ren shen",this_player());
ob=new("/obj/jineng/medical/jinchuang.c");
ob->move(me);
me->start_busy(3);
destruct(ob1); 
destruct(ob2); 
done(me);
break;
        default:   notify_fail("��û������������ҩ��\n");
        
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

int help(object me) 
{
write(@HELP 
ָ���ʽ : makeyao <��Ʒ> 
���ָ����������ҩ��ã�����Ҫ����quest�õ�
  �鵤  ���˲κ�ţ�����Ƶĵ�ҩ��
HELP 
);
 return 1; 
}
