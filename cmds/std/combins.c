 // combine.c  
  
#include <ansi.h>  
  
inherit F_CLEAN_UP;  
#define BAOSHI "/d/quest/baoshi/baoshi" 
  
 
 
int main(object me, string arg)  
{  
                        
        object *ob_list, *ilist;                // �ϲ���������Ʒ  
                        
        object obj,base;                     // ���ɵ���Ʒ  
        int i,k,j;  
  
        if (! arg )  
                return notify_fail("��Ҫ�ϲ�ʲô��Ʒ��\n");  
 
        if ( arg=="baoshi" )  
                return notify_fail("��Ҫ�ϲ�ʲô��ʯ��\n");   
        if (me->is_busy())  
                return notify_fail("��æ����������������������ɣ�\n");  
  
        if (me->is_fighting())  
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n"); 
        if (!( base=present (arg,me))) 
                return notify_fail("������û�������Ʒ��\n"); 
        if (!base->query("b_lvl")) 
                return notify_fail("�����������Ʒ�����ںϡ�\n"); 
      i=base->query("b_lvl");
        if ( i > 28) 
                return notify_fail("�����������Ʒ�Ѿ������ںϡ�\n"); 
        if (me->query("max_sen") < 1000)  
                return notify_fail("�����ڵľ�����Ϊ���ޣ���"  
                                   "��ʩչ��˼���ķ�����\n");  
           
        if (me->query("sen") < 1000)  
                return notify_fail("�����ھ��񲻼ã��޷�ʩչ������\n");  
       if(arg=="hong baoshi")
           i=1;
       ilist = all_inventory(me); 
        if (!ilist) 
                return notify_fail("������û���κ���Ʒ��\n"); 
       k=0; 
// 
//       i=base->query("b_lvl"); 
       j = sizeof(ilist); 
        while (j--) { 
        //      object ob =; 
                if( ilist[j]->query("b_lvl")!=i) 
                { 
                          continue; 
                        } 
             
              k++; 
        } 
        if(k <=2) 
         return notify_fail("��Ҫ�ϲ��ı�ʯ������������\n");  
        obj=new(BAOSHI); 
       i=i+7;
        BAOSHI->changename(obj,i);  
        k=3; 
        ilist = all_inventory(me); 
         for (j = 0; j<3; j++) {
             base=present (arg,me);
                      destruct(base);
                        } 
             
               
         
        message_vision(HIM "$N" HIM "��һЩ��Ʒ��"  
                       "��һ��Ĭ����ͨʹ���Ǳ仯��\n" NOR, me);  
        if(obj->move(me)){ 
        message_vision(HIW "������â�������ƺ�������"  
                                       "��ͬѰ�������顣\n" NOR, me);  
        tell_object(me, HIC "��������ͷ����Ʒ������" + obj->name() +  
                                        HIC "��\n" NOR);  
                                }else 
                                { 
                    message_vision(HIG "���˰��죬�ƺ�û���κα仯��$N"  
                       HIG "һ���㬡�\n", me);    }             
        me->start_busy(4);  
        me->add("sen", -500);  
          return 1;  
        
}  
  
int help(object me)  
{  
write(@HELP  
ָ���ʽ : combins <������Ʒ>  
  
���ָ��������㽫ĳЩ������Ʒ�ϲ���һ���µ���Ʒ����Щ���ܺ�  
�������Ҫ����ȥ�����ˡ�ÿ�κϲ�������ʧһЩ���������ޡ����  
Ҫ�ϲ��ļ�����Ʒ������ͬ������Ҫָ�����ǵ���ţ�������������  
ʯ��Ƭ�����Ҫ��һ������Ҫ���룺  
  
combins xxx baoshi 
  
HELP  
    );  
    return 1;  
}  
  
  

