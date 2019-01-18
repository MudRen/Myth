#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"��ˮ֮��","where":"/d/changan/wside1"]),   
         ([ "sxy":"��ˮ�ű�","where":"/d/changan/nbridge"]),   
         ([ "sxy":"��ٵ�","where":"/d/changan/broadway1"]),   
         ([ "sxy":"����","where":"/d/changan/nanyue"]),   
         ([ "sxy":"�Ϻ�֮��","where":"/d/changan/southseashore"]),   
         ([ "sxy":"�߼Ҵ���","where":"/d/gao/gate"]),   
         ([ "sxy":"�꾩����","where":"/d/kaifeng/tieta"]),   
         ([ "sxy":"Ң����","where":"/d/kaifeng/yao5"]),   
         ([ "sxy":"��ͤ��","where":"/d/kaifeng/guting3"]),   
         ([ "sxy":"����·","where":"/d/kaifeng/xihu6"]),    
         ([ "sxy":"������","where":"/d/kaifeng/yuwang1"]),    
         ([ "sxy":"������","where":"/d/city/southjie3"]),    
         ([ "sxy":"�������","where":"/d/kaifeng/chengmen"]),    
         ([ "sxy":"���Ͻ�","where":"/d/eastway/wangnan5"]),
         ([ "sxy":"ʮ�ֽ�ͷ","where":"/d/city/center"]),
         ([ "sxy":"�������","where":"/d/city/qinglong-e1"]),   
         ([ "sxy":"�������","where":"/d/city/qinglong-e2"]),   
         ([ "sxy":"�������","where":"/d/city/qinglong-e3"]),   
         ([ "sxy":"�����Ƕ���","where":"/d/city/dongmen"]),   
         ([ "sxy":"������","where":"/d/city/xuanwu-n1"]),   
         ([ "sxy":"������","where":"/d/huanggong/chaoyangmen"]),   
         ([ "sxy":"��ȸ���","where":"/d/city/zhuque-s1"]),   
         ([ "sxy":"��ȸ���","where":"/d/city/zhuque-s2"]),   
         ([ "sxy":"��ȸ���","where":"/d/city/zhuque-s3"]),   
         ([ "sxy":"��ȸ���","where":"/d/city/zhuque-s4"]),   
         ([ "sxy":"�ϳǿ�","where":"/d/changan/nanchengkou"]),   
         ([ "sxy":"�׻����","where":"/d/city/baihu-w1"]),   
         ([ "sxy":"�׻����","where":"/d/city/baihu-w2"]),   
         ([ "sxy":"�׻����","where":"/d/city/baihu-w3"]),    
         ([ "sxy":"����������","where":"/d/city/ximen"]),    
         ([ "sxy":"������","where":"/d/city/beiyin1"]),    
         ([ "sxy":"������","where":"/d/city/beiyin2"]),    
         ([ "sxy":"������","where":"/d/city/beiyin3"]),    
         ([ "sxy":"������","where":"/d/city/beiyin4"]),    
         ([ "sxy":"������","where":"/d/city/beiyin5"]),    
         ([ "sxy":"�������","where":"/d/city/minju1"]),   
         ([ "sxy":"�������","where":"/d/city/minju2"]),   
         ([ "sxy":"�������","where":"/d/city/minju3"]),   
         ([ "sxy":"�������","where":"/d/city/minju4"]),   
         ([ "sxy":"�������Ͻ�","where":"/d/eastway/wangnan1"]),   
         ([ "sxy":"�������Ͻ�","where":"/d/eastway/wangnan2"]),   
         ([ "sxy":"�������Ͻ�","where":"/d/eastway/wangnan3"]),   
         ([ "sxy":"�������Ͻ�","where":"/d/eastway/wangnan4"]),   
         ([ "sxy":"�������Ͻ�","where":"/d/eastway/wangnan5"]),   
         ([ "sxy":"�ش�ҩ��","where":"/d/city/yaopu"]),   
         ([ "sxy":"Ьñ��","where":"/d/city/xiemao"]),   
         ([ "sxy":"����Ƥ����","where":"/d/city/maohuo"]),   
         ([ "sxy":"�����ӻ���","where":"/d/city/zahuopu"]),   
         ([ "sxy":"�������","where":"/d/city/wuguan"]),   
         ([ "sxy":"�������","where":"/d/city/wuguanzhong"]),   
         ([ "sxy":"������","where":"/d/city/bingqipu"]), 
         ([ "sxy":"������","where":"/d/city/huashengsi"]), 
         ([ "sxy":"���۱���","where":"/d/city/baodian"]), 
         ([ "sxy":"������","where":"/d/city/fangzhang"]), 
         ([ "sxy":"Ԭ�ϲ���","where":"/d/city/caotang"]), 
         ([ "sxy":"С������","where":"/d/eastway/xyt1"]), 
         ([ "sxy":"С������","where":"/d/eastway/xyt10"]), 
         ([ "sxy":"��������","where":"/d/eastway/dyt1"]), 
         ([ "sxy":"��������","where":"/d/eastway/dyt3"]), 
         ([ "sxy":"��������","where":"/d/eastway/dyt5"]),    
                });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIB "���������������ʱ�޵��ˣ����ȥ�����\n" NOR );     
      me->delete("job/sxy");
      me->set("job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "��������سǲ����������Ҵ���ѽ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼ�������˴������" + sxy["sxy"] + "���������ֵ��ټ���\n" NOR );
        ob = new("/d/obj/npc/yaoguai");
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "����س�������ʱ�޵��ˣ����ȥ�����\n" NOR );
      me->delete("job/sxy");
      me->set("job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}
