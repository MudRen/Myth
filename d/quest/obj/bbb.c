//make bye stey
#include <ansi.h>  
inherit ITEM;  
string *names = ({   
  "��",   
  "��",   
  "��",   
  "��",   
  "��",   
  "��",   
  "��",//����7��  
  "���", 
  "���", 
  "����", 
  "ˮ��", 
  "��ɳ", 
  "è��", 
  "��ʯ",//�м�7�� 
  "��֮���", 
  "��֮���", 
  "��֮����", 
  "��֮ˮ��", 
  "��֮��ɳ", 
  "��֮è��", 
  "��֮��ʯ",//�߼�7�� 
  "����",   
  "���",   
  "ɭ��",   
  "����",   
  "����",   
  "��ϼ",   
  "ɳĮ",//�ռ�7�� 
   
   
});   
string *ids = ({   
  "hong",   
  "blue",   
  "green",   
  "qing",   
  "huang",   
  "zi",   
  "cheng",//����7��  
  "manao", 
  "feicui", 
  "chengyu", 
  "shuijing", 
  "jinsha", 
  "maoyan", 
  "zuanshi",//�м�7�� 
  "god manao", 
  "god feicui", 
  "god chengyu", 
  "god shuijing", 
  "god jinsha", 
  "god maoyan", 
  "god zuanshi",//�߼�7�� 
  "sun",   
  "sky",   
  "forest",   
  "sea",   
  "fire",   
  "sunshine",   
  "sand",//�ռ�7�� 
   
   
});   
 
 
void setname()  
{  
    int i, j,k;  
    string name, *id;  
    k=random(1000); 
 //   i=(random(sizeof(names4)/2))*2;  
       if(k>995){ 
        i=21+random(7); 
        j=i-21; 
        set("is_monitored", 1); 
    }else if(k>960){ 
        i=14+random(7); 
        j=i-14; 
        set("is_monitored", 1);  
      }else if (k>800) 
         { i=7+random(7); 
         j=i-7; 
         set("is_monitored", 1);  
        }else  
        { i=random(7); 
        j=i;} 
     set("b_lvl",i+1); 
           
    name=names[i]+"��ʯ";  
    set("baoshi",names[i]); 
    id=({ids[i]+" baoshi","baoshi"}); 
    set("reward_lvl",j+1); 
    if(j==0){ 
        set("reward_lvl",j); 
    set_name(BLINK+HIR+name+NOR,id); } 
    if(j==1){ 
    set_name(BLINK+HIB+name+NOR,id); } 
    if(j==2){ 
    set_name(BLINK+HIG+name+NOR,id); } 
    if(j==3){ 
    set_name(BLINK+HIC+name+NOR,id); } 
    if(j==4){ 
    set_name(BLINK+HIY+name+NOR,id); } 
    if(j==5){ 
    set_name(BLINK+HIM+name+NOR,id); } 
    if(j==6){ 
    set_name(BLINK+YEL+name+NOR,id); } 
    if(j==7){ 
    set_name(BLINK+YEL+name+NOR,id); } 
}     
void create()  
{  
        setname(); 
        set_weight(500);  
        if( clonep() )  
                set_default_object(__FILE__);  
        else {  
       set("value", 2000000);   
 //               set("is_monitored", 1);  
                set("unit","��");  
                set("color","b");  //HIB  
//                set("no_put",1);  
                set("no_sell",1);  
                set("long",HIB"һ�鷢����������ı�ʯ����˵��Ů洲���ʯ�����,Ҳ��֪��ʲôʱ�����뷲��ġ�\n"NOR);  
        }  
        setup();  
}  
 
 
void init()  
{  
      
    add_action("do_enchase", "enchase");  
    add_action("do_enchase", "inset");  
}  
 
 
int do_enchase(string arg)  
{  
   object in_obj;  
   string item,str,mats;  
    
   int rd,inset_num ,i,j,k;  
   object me = this_player();  
   object ob = this_object();  
    
   if(!arg) return notify_fail("��Ҫ��ʲô��\n");  
   if(sscanf(arg, "%s", item)!=1) return notify_fail("��Ҫ�ѱ�ʯ��Ƕ��ʲô�ϣ�\n");  
   if(!objectp(in_obj = present(item, me))) return notify_fail("������û������������\n");  
    
   if( in_obj->query("equipped") )  
      return notify_fail("����������������������Ƕ��ʯ��\n");  
//   if( in_obj->query("no_zm")||in_obj->query_unique())  
//      return notify_fail("���װ��������Ƕ��ʯ��\n");  
   i=ob->query("b_lvl"); 
    if(i>21) k=5; 
    else if(i > 14) k=3; 
    else if(i > 7) k=2; 
    else k=1; 
    j=ob->query("reward_lvl"); 
   mats = in_obj->query("material");       //װ��������  
   inset_num = in_obj->query("inset_num");  // Ƕ�˼�����  
   if(!inset_num) inset_num = 1;  
   else inset_num = inset_num + 1;  
   if(inset_num > 6) return notify_fail(in_obj->query("name")+"���Ѿ���Ƕ��̫��ı�ʯ��!\n");  
     
   if(!in_obj->query("weapon_prop/damage"))   //����  
  {  
        
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);  
       tell_room(environment(me),HIB"ֻ��"+ob->name()+HIB"����һ��"+names[j-1]+"��,������"+in_obj->query("name")+HIB"����,������! \n"NOR);  
 //�ж�ͬ�౦ʯ     
      if(j==1){  
       in_obj->add("armor_prop/dodge",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø�����ӯ�ˣ�\n"NOR,me);  
             } 
        if(j==2){  
       in_obj->add("armor_prop/spell",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��ӳ��������ˣ�\n"NOR,me);  
        } 
        if(j==3){ 
       in_obj->add("armor_prop/armor",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��Ӽ�ʵ�ˣ�\n"NOR,me);  
        } 
        if(j==4){  
      in_obj->add("armor_prop/dodge",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø�����ӯ�ˣ�\n"NOR,me);  
              } 
           if(j==5){  
                 
        in_obj->add("armor_prop/spell",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��ӳ��������ˣ�\n"NOR,me);  
      } 
         if(j==6){  
       in_obj->add("armor_prop/dodge",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø�����ӯ�ˣ�\n"NOR,me);  
        } 
        if(j==7){  
        in_obj->add("armor_prop/armor",k*2+random(k*5));  
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��Ӽ�ʵ�ˣ�\n"NOR,me);  
        } 
     //  me->add("bellicosity",1000);    
       in_obj->set_weight(in_obj->query_weight()+1000);  
         
       in_obj->set("inset_num",inset_num);  
       in_obj->set("no_sell",1);  
       in_obj->add("inset_b",inset_num);  //װ��b  
       in_obj->set("name",HIG+in_obj->query("name")+NOR);  
       if(!in_obj->query("old_long")) 
         in_obj->set("old_long",in_obj->query("long"));  
         
       if(!in_obj->query("old_ee")) 
          in_obj->set("old_ee",ob->query("name"));  
          else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));  
              
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"+HIW+chinese_number(inset_num)+"�ű�ʯ:"+in_obj->query("old_ee")+"��\n"NOR); 
        
       in_obj->save();  
       destruct(ob);  
       return 1;  
}else{  
//����  
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);  
       tell_room(environment(me),HIB"ֻ��"+ob->name()+HIB"����һ��"+names[j-1]+"��,������"+in_obj->query("name")+HIB"����,������! \n"NOR);  
        
         message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø������������ˣ�\n"NOR,me);  
       if(k>2) { 
        in_obj->set("material","diamond"); 
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��Ӽ�ʵ�ˣ�\n"NOR,me);} 
       in_obj->add("weapon_prop/damage",k*2+random(k*5));  
       in_obj->add("weapon_prop/intelligence",k*2+random(k*5));  
       in_obj->set_weight(in_obj->query_weight()+1000);  
       in_obj->set("no_sell",1);         
       in_obj->set("inset_num",inset_num);  
       in_obj->add("inset_b",inset_num);  //װ��g  
       in_obj->set("name",HIG+in_obj->query("name")+NOR);  
       if(!in_obj->query("old_long")) 
         in_obj->set("old_long",in_obj->query("long"));  
         
       if(!in_obj->query("old_ee")) 
          in_obj->set("old_ee",ob->query("name"));  
          else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));  
              
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"+HIW+chinese_number(inset_num)+"�ű�ʯ:"+in_obj->query("old_ee")+"��\n"NOR); 
       in_obj->save();  
       destruct(ob);  
       return 1;  
}  
  
  
   
  return notify_fail("����Ƕ��ʯʧ���ˣ�\n");  
}  
  
  

