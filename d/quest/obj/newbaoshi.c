//make bye stey 
#include <ansi.h> 
inherit ITEM; 
 
void setname() 
{ 
    int i, j,k; 
    string name, *id,ids; 
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
        i=i+1; 
        switch(i){ 
                case 1:   name="��";         ids="hong";        break; 
                case 2:   name="��";         ids="blue";        break; 
                case 3:   name="��";         ids="green";       break; 
                case 4:   name="��";         ids="qing";        break; 
                case 5:   name="��";         ids="huang";       break; 
                case 6:   name="��";         ids="zi";          break; 
                case 7:   name="��";         ids="cheng";       break; 
                case 8:   name="���";       ids="manao";       break; 
                case 9:   name="���";       ids="feicui";      break; 
                case 10:   name="����";      ids="chengyu";     break; 
                case 11:   name="ˮ��";      ids="shuijing";    break; 
                case 12:   name="��ɳ";      ids="jinsha";      break; 
                case 13:   name="è��";      ids="maoyan";      break; 
                case 14:   name="��ʯ";      ids="zuanshi";     break; 
                case 15:   name="��֮���";  ids="god manao";    break; 
                case 16:   name="��֮���";  ids="god feicui";   break; 
                case 17:   name="��֮����"; ids="god chengyu";  break; 
                case 18:   name="��֮ˮ��"; ids="god shuijing"; break; 
                case 19:   name="��֮��ɳ"; ids="god jinsha";   break; 
                case 20:   name="��֮è��"; ids="god maoyan";   break; 
                case 21:   name="��֮��ʯ"; ids="god zuanshi";  break; 
                case 22:   name="����";    ids="sun";         break; 
                case 23:   name="���";    ids="sky";         break; 
                case 24:   name="ɭ��";    ids="forest";      break; 
                case 25:   name="����";    ids="sea";         break; 
                case 26:   name="����";    ids="fire";        break; 
                case 27:   name="��ϼ";    ids="sunshine";    break; 
                case 28:   name="ɳĮ";    ids="sand";        break; 
 
                } 
    name=name+"��ʯ"; 
    set("baoshi",name); 
    id=({ids+" baoshi","baoshi"}); 
    set("reward_lvl",j+1); 
    if(j==0){ 
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
void changename(object ob,int i) 
{ 
    int j,k; 
    string name, *id,ids; 
     
       if(i>21){ 
 
        j=i-21; 
        ob->set("is_monitored", 1); 
    }else if(i>14){ 
 
        j=i-14; 
       ob->set("is_monitored", 1); 
      }else if (i>7) 
         { 
         j=i-7; 
         ob->set("is_monitored", 1); 
        }else 
        { 
        j=i;} 
     ob->set("b_lvl",i); 
 
        switch(i){ 
                case 1:   name="��";         ids="hong";        break; 
                case 2:   name="��";         ids="blue";        break; 
                case 3:   name="��";         ids="green";       break; 
                case 4:   name="��";         ids="qing";        break; 
                case 5:   name="��";         ids="huang";       break; 
                case 6:   name="��";         ids="zi";          break; 
                case 7:   name="��";         ids="cheng";       break; 
                case 8:   name="���";       ids="manao";       break; 
                case 9:   name="���";       ids="feicui";      break; 
                case 10:   name="����";      ids="chengyu";     break; 
                case 11:   name="ˮ��";      ids="shuijing";    break; 
                case 12:   name="��ɳ";      ids="jinsha";      break; 
                case 13:   name="è��";      ids="maoyan";      break; 
                case 14:   name="��ʯ";      ids="zuanshi";     break; 
                case 15:   name="��֮���";  ids="god manao";    break; 
                case 16:   name="��֮���";  ids="god feicui";   break; 
                case 17:   name="��֮����"; ids="god chengyu";  break; 
                case 18:   name="��֮ˮ��"; ids="god shuijing"; break; 
                case 19:   name="��֮��ɳ"; ids="god jinsha";   break; 
                case 20:   name="��֮è��"; ids="god maoyan";   break; 
                case 21:   name="��֮��ʯ"; ids="god zuanshi";  break; 
                case 22:   name="����";    ids="sun";         break; 
                case 23:   name="���";    ids="sky";         break; 
                case 24:   name="ɭ��";    ids="forest";      break; 
                case 25:   name="����";    ids="sea";         break; 
                case 26:   name="����";    ids="fire";        break; 
                case 27:   name="��ϼ";    ids="sunshine";    break; 
                case 28:   name="ɳĮ";    ids="sand";        break; 
 
        } 
           name=name+"��ʯ"; 
    ob->set("baoshi",name); 
    id=({ids+" baoshi","baoshi"}); 
        set("baoshi",name); 
    ob->set("reward_lvl",j); 
    if(j==1){ 
 
    ob->set_name(BLINK+HIR+name+NOR,id); } 
    if(j==2){ 
    ob->set_name(BLINK+HIB+name+NOR,id); } 
    if(j==3){ 
    ob->set_name(BLINK+HIG+name+NOR,id); } 
    if(j==4){ 
    ob->set_name(BLINK+HIC+name+NOR,id); } 
    if(j==5){ 
    ob->set_name(BLINK+HIY+name+NOR,id); } 
    if(j==6){ 
    ob->set_name(BLINK+HIM+name+NOR,id); } 
    if(j==7){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
    if(j==0){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
} 
void create(int i) 
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
       tell_room(environment(me),HIB"ֻ��"+ob->name()+HIB"����һ����ֵĹ�,������"+in_obj->query("name")+HIB"����,������! \n"NOR); 
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
       tell_room(environment(me),HIB"ֻ��"+ob->name()+HIB"����һ�����,������"+in_obj->query("name")+HIB"����,������! \n"NOR); 
 
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
 
 
 

